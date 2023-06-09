package Model;

import javax.swing.*;
import java.awt.*;
public class ButtonPanel extends JPanel{
    private JButton addTask;
    private JButton removeTask;

    private JTextField enterTask;

    //Конструктор
    public ButtonPanel() {
        this.setPreferredSize(new Dimension(400, 80));

        addTask = new JButton("Добавить дело");
        removeTask = new JButton("Очистить выполненное");
        enterTask = new JTextField("");

        this.setBackground(new Color(194, 150, 229));

        addTask.setBackground(new Color(209, 176, 232));
        removeTask.setBackground(new Color(209, 176, 232));
        enterTask.setBackground(new Color(209, 176, 232));

        addTask.setPreferredSize(new Dimension(110, 30));
        removeTask.setPreferredSize(new Dimension(160, 30));
        enterTask.setPreferredSize(new Dimension(160, 30));

        addTask.setBorder(BorderFactory.createEmptyBorder());
        removeTask.setBorder(BorderFactory.createEmptyBorder());
        enterTask.setBorder(BorderFactory.createEmptyBorder());

        this.add(Box.createVerticalStrut(70));
        this.add(addTask);
        this.add(Box.createHorizontalStrut(20));
        this.add(removeTask);
        this.add(Box.createHorizontalStrut(20));
        this.add(enterTask);

    }

    //Добавление новой задачи
    public JButton getAddTask() {
        return addTask;
    }

    //Удаление выполненных задач
    public JButton getRemoveTask() {
        return removeTask;
    }

    //Получение данных строки
    public JTextField getEnterTask() {return enterTask; }
}
