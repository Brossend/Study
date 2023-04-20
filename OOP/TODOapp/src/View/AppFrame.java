package View;

import Model.ButtonPanel;
import Model.Task;
import Model.TitleBar;
import Model.List;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;


public class AppFrame extends JFrame {
    private TitleBar titleBar;
    private List list;
    private ButtonPanel buttonPanel;
    private JButton newTask;
    private JButton removeTask;
    private JTextField enterTask;
    private JFrame window;

    public static ArrayList<String> result = new ArrayList<>();
    private String temp;

    //Конструктор окна
    public AppFrame() throws FileNotFoundException {
        window = new JFrame("Разработал: Лямцев И.А., ИСТ-213");

        titleBar = new TitleBar();
        list = new List();
        buttonPanel = new ButtonPanel();

        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setSize(700, 700);
        window.setVisible(true);

        window.add(titleBar, BorderLayout.NORTH);
        window.add(buttonPanel, BorderLayout.SOUTH);
        window.add(list, BorderLayout.CENTER);

        newTask = buttonPanel.getAddTask();
        removeTask = buttonPanel.getRemoveTask();
        enterTask = buttonPanel.getEnterTask();

        savedTODO();
        addListener();
    }

    public void savedTODO() throws FileNotFoundException {
        File file = new File("test.txt");

        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            temp = scanner.nextLine();

            result.add(temp);

            list.revalidate();
            Task task = new Task(temp);
            list.add(task);
            list.updatePosition();

            task.getDoneTask().addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    task.changeState();
                    list.revalidate();
                }
            });
        }

        list.revalidate();
    }

    //Изменение состояния объектов с помощью клика на кнопки
    public void addListener() {
        //Рисуем задание и его номер
        newTask.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                list.revalidate();
                Task task = new Task(enterTask.getText());
                list.add(task);
                list.updatePosition();

                result.add(enterTask.getText());

                FileWriter writer = null;

                try {
                    writer = new FileWriter("test.txt");
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }

                for(String str: result) {
                    try {
                        writer.write(str + System.lineSeparator());
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                }

                try {
                    writer.close();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }

                //Изменяем состояние при клике на кнопку выполнения
                task.getDoneTask().addMouseListener(new MouseAdapter() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        task.changeState();
                        list.revalidate();
                    }
                });
                list.revalidate();
            }
        });
        //Удаляем выполенные задачи
        removeTask.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                try {
                    list.removeCompletedTasks();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
                list.repaint();
            }
        });
    }
    public JFrame getWindow() { return window; }
    public TitleBar getTitleBar() { return titleBar; }
    public ButtonPanel getButtonPanel() { return buttonPanel; }
    public List getList() { return list; }
}