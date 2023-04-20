package Tests;

import View.AppFrame;
import org.junit.jupiter.api.Test;

import java.io.FileNotFoundException;

import static org.junit.jupiter.api.Assertions.*;

class AppFrameTest {

    @Test
    void getWindow() throws FileNotFoundException {
        AppFrame appFrame = new AppFrame();
        assertNotNull(appFrame.getWindow());

        assertEquals(appFrame.getWindow().getTitle(), "Разработал: Лямцев И.А., ИСТ-213");
    }

    @Test
    void getTitleBar() throws FileNotFoundException {
        AppFrame appFrame = new AppFrame();
        assertNotNull(appFrame.getTitleBar());
    }

    @Test
    void getButtonPanel() throws FileNotFoundException {
        AppFrame appFrame = new AppFrame();
        assertNotNull(appFrame.getButtonPanel());
    }

    @Test
    void getList() throws FileNotFoundException {
        AppFrame appFrame = new AppFrame();
        assertNotNull(appFrame.getList());
    }
}