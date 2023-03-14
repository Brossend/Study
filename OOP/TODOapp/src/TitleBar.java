import javax.swing.*;
import java.awt.*;

public class TitleBar extends JPanel {
    //Конструктор
    TitleBar() {
        this.setPreferredSize(new Dimension(400, 80));

        JLabel titleText = new JLabel("Ежедневник");
        titleText.setPreferredSize(new Dimension(125, 80));
        titleText.setFont(new Font("Sans-serif", Font.BOLD, 20));

        this.add(titleText);
    }
}
