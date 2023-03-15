package Model;

import javax.swing.*;
import java.awt.*;

public class List extends JPanel {
    //Конструктор блока с задачами
    public List() {
        GridLayout layout = new GridLayout(10, 1);
        this.setBackground(new Color(181, 122, 229));
        layout.setVgap(5);

        this.setLayout(layout);
        this.setPreferredSize(new Dimension(400,560));
    }
    //Добавляем номер задания
    public void updatePosition() {
        Component[] listItems = this.getComponents();

        for(int i = 0; i < listItems.length; i++) {
            if(listItems[i] instanceof Task) {
                ((Task)listItems[i]).changeIndex(i + 1);
            }
        }
    }
    //Удаляем выделеные задания
    public void removeCompletedTasks() {
        for(Component c : getComponents()) {
            if(c instanceof Task)
            {
                if(((Task)c).getState())
                {
                    remove(c);
                    updatePosition();
                }
            }
        }
    }
}
