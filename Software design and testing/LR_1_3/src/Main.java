import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int size;
        int number;

        while (true) {
            System.out.print("Размер цифр (Не более 10)\nВвод: ");
            size = in.nextInt();

            if(size > 0 && size <= 10) {
                break;
            }
            else {
                System.out.println("\nВы ввели некорректный размер\n");
            }
        }

        while (true) {
            System.out.print("Введите число! (От 0 до 99 999 999)\nВвод: ");
            number = in.nextInt();

            if(0 > number || number > 99999999) {
                System.out.print("\nВы ввели некорректное число!р\n");
            } else {
                break;
            }
        }

        String line [] = Integer.toString(number).split("(?!^)");

        for (String value: line) {
            switch (value) {
                case "1":
                    break;
                case "2":
                    break;
                case "3":
                    break;
                case "4":
                    break;
                case "5":
                    break;
                case "6":
                    break;
                case "7":
                    break;
                case "8":
                    break;
                case "9":
                    break;
                case "0":
                    break;
            }
        }
    }
}