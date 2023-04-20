package Model;

import View.AppFrame;

import javax.swing.*;
import java.awt.*;
import java.io.FileWriter;
import java.io.IOException;

public class List extends JPanel {
    String temp;
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
    public void removeCompletedTasks() throws IOException {
        for(Component c : getComponents()) {
            if(c instanceof Task)
            {
                if(((Task)c).getState())
                {
                    temp = ((Task) c).getResult();

                    for(String string : AppFrame.result) {
                        if (string.equals(temp)) {
                            AppFrame.result.remove(string);
                        }
                    }

                    FileWriter writer = new FileWriter("test.txt");
                    for(String string: AppFrame.result) {
                        writer.write(string + System.lineSeparator());
                    }

                    writer.close();

                    remove(c);
                    updatePosition();
                }
            }
        }
    }
}
