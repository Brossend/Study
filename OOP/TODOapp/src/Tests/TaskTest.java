package Tests;

import Model.Task;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TaskTest {

    @Test
    void changeState() {
        Task task = new Task("Купить макарошки");
        assertTrue(task.changeState());
    }

    @Test
    void getDoneTask() {
        Task task = new Task("Купить макарошки");
        assertNotNull(task.getDoneTask());
    }

    @Test
    void getIndex() {
        Task task = new Task("Купить макарошки");
        assertNotNull(task.getIndex());
    }

    @Test
    void getTaskName() {
        Task task = new Task("Купить макарошки");
        assertNotNull(task.getTaskName());
    }

    @Test
    void getState() {
        Task task = new Task("Купить макарошки");
        assertFalse(task.getState());
    }

    @Test
    void getResult() {
        String test = "Купить макарошки";
        Task task = new Task(test);
        assertEquals(test, task.getResult());
    }
}