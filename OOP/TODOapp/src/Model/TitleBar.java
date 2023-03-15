package Model;

import javax.swing.*;
import java.awt.*;

public class TitleBar extends JPanel {
    //Конструктор верхнего блока
    public TitleBar() {
        this.setPreferredSize(new Dimension(400, 80));
        this.setBackground(new Color(194, 150, 229));

        JLabel titleText = new JLabel("Ежедневник");

        titleText.setPreferredSize(new Dimension(125,  70));
        titleText.setFont(new Font("Sans-serif", Font.BOLD, 20));

        this.add(titleText);
    }
}
