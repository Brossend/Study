import javax.swing.*;
import java.awt.*;
public class ButtonPanel extends JPanel{
    private JButton addTask;
    private JButton removeTask;

    //Конструктор
    ButtonPanel() {
        this.setPreferredSize(new Dimension(400, 50));

        addTask = new JButton("Добавить дело");
        removeTask = new JButton("Очистить выполненное");

        this.add(addTask);
        this.add(Box.createHorizontalStrut(20));
        this.add(removeTask);
    }

    //Добавление новой задачи
    public JButton getAddTask() {
        return addTask;
    }

    //Удаление выполненных задач
    public JButton getRemoveTask() {
        return removeTask;
    }
}
