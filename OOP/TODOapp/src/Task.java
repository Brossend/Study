import javax.swing.*;
import java.awt.*;

public class Task extends JPanel {
    private JLabel index;
    private JTextField taskName;
    private JButton doneTask;
    private boolean check;
    //Конструктор
    Task() {
        this.setPreferredSize(new Dimension(40, 20));
        this.setLayout(new BorderLayout());

        check = false;

        index = new JLabel("");
        index.setPreferredSize(new Dimension(20, 20));
        index.setHorizontalAlignment(JLabel.CENTER);

        this.add(index, BorderLayout.WEST);

        taskName = new JTextField("Введите задание здесь");
        taskName.setBorder(BorderFactory.createEmptyBorder());

        this.add(taskName, BorderLayout.CENTER);

        doneTask = new JButton("Done");
        doneTask.setPreferredSize(new Dimension(20, 40));
        doneTask.setBorder(BorderFactory.createEmptyBorder());

        this.add(doneTask, BorderLayout.EAST);
    }
    public void changeIndex(int num) {
        this.index.setText(num + "");
    }
    public void changeState() {
        this.setBackground(Color.green);
        taskName.setBackground(Color.green);
        check = true;
        revalidate();
    }

    public JButton getDoneTask() {
        return doneTask;
    }
    public boolean getState() {
        return check;
    }
}
