package View;

import Model.ButtonPanel;
import Model.Task;
import Model.TitleBar;
import Model.List;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class AppFrame extends JFrame {
    private TitleBar titleBar;
    private List list;
    private ButtonPanel buttonPanel;
    private JButton newTask;
    private JButton removeTask;
    //Конструктор окна
    public AppFrame() {
        JFrame window = new JFrame("Разработал: Лямцев И.А., ИСТ-213");

        titleBar = new TitleBar();
        list = new List();
        buttonPanel = new ButtonPanel();

        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setSize(400, 700);
        window.setVisible(true);

        window.add(titleBar, BorderLayout.NORTH);
        window.add(buttonPanel, BorderLayout.SOUTH);
        window.add(list, BorderLayout.CENTER);

        newTask = buttonPanel.getAddTask();
        removeTask = buttonPanel.getRemoveTask();

        addListener();
    }
    //Изменение состояния объектов с помощью клика на кнопки
    public void addListener() {
        //Рисуем задание и его номер
        newTask.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                list.revalidate();
                Task task = new Task();
                list.add(task);
                list.updatePosition();

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
                list.removeCompletedTasks();
                list.repaint();
            }
        });
    }
}
