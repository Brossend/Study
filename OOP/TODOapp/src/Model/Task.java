package Model;

import javax.swing.*;
import java.awt.*;

public class Task extends JPanel {
    private JLabel index;
    private JTextField taskName;
    private JButton doneTask;
    private boolean check;
    private String result;
    //Конструктор задания
    public Task(String text)  {
        this.setPreferredSize(new Dimension(40, 20));
        this.setLayout(new BorderLayout());
        this.setBackground(new Color(194, 150, 229));

        check = false;

        index = new JLabel("");
        index.setPreferredSize(new Dimension(50, 40));
        index.setHorizontalAlignment(JLabel.CENTER);

        this.add(index, BorderLayout.WEST);

        JLabel taskName = new JLabel(text);

        result = taskName.getText();

        taskName.setBackground(new Color(194, 150, 229));
        taskName.setBorder(BorderFactory.createEmptyBorder());

        this.add(taskName, BorderLayout.CENTER);

        doneTask = new JButton("Готово");
        doneTask.setPreferredSize(new Dimension(60, 40));
        doneTask.setBackground(new Color(204, 159, 234));
        doneTask.setBorder(BorderFactory.createEmptyBorder());

        this.add(doneTask, BorderLayout.EAST);
    }
    //Добавляем номер задания
    public void changeIndex(int num) {
        this.index.setText(num + "");
    }
    //Выделяем выполенное
    public void changeState() {
        this.setBackground(new Color(145, 215, 148));
        doneTask.setBackground(new Color(145, 215, 148));
        check = true;
        revalidate();
    }
    //Получаем кнопку выполнения задачи
    public JButton getDoneTask() {
        return doneTask;
    }
    //Получаем поле для проверки состояния задания
    public boolean getState() {
        return check;
    }

    public String getResult() { return result; }
}
