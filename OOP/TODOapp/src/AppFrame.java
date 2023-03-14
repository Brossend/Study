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
    //Конструктор
    AppFrame() {
        JFrame window = new JFrame("Ежедневник");

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
    public void addListener() {
        newTask.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                list.revalidate();
                Task task = new Task();
                list.add(task);
                list.updatePosition();

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

        removeTask.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                list.removeCompletedTasks();
                list.repaint();
            }
        });
    }
}
