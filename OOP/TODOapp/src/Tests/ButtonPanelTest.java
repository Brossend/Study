package Tests;

import Model.ButtonPanel;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ButtonPanelTest {

    @Test
    void getAddTask() {
        ButtonPanel buttonPanel = new ButtonPanel();
        assertNotNull(buttonPanel.getAddTask());
    }

    @Test
    void getRemoveTask() {
        ButtonPanel buttonPanel = new ButtonPanel();
        assertNotNull(buttonPanel.getRemoveTask());
    }

    @Test
    void getEnterTask() {
        ButtonPanel buttonPanel = new ButtonPanel();
        assertNotNull(buttonPanel.getEnterTask());
    }
}