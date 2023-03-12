import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Numbers nums = new Numbers();

        int size;
        int number;

        while (true) {

            while (true) {
                System.out.print("Размер цифр (Не более 10)\nВвод: ");
                size = in.nextInt();

                if (size >= 0 && size <= 10) {
                    break;
                } else {
                    System.out.println("\nВы ввели некорректный размер\n");
                }
            }

            while (true) {
                System.out.print("Введите число! (От 0 до 99 999 999)\nВвод: ");
                number = in.nextInt();

                if (0 > number || number > 99999999) {
                    System.out.print("\nВы ввели некорректное число!р\n");
                } else {
                    break;
                }
            }

            if(size == 0 && number == 0) {
                break;
            }

            String line[] = Integer.toString(number).split("(?!^)");

            for (String value : line) {
                switch (value) {
                    case "1":
                        nums.one(size);
                        break;
                    case "2":
                        nums.two(size);
                        break;
                    case "3":
                        nums.three(size);
                        break;
                    case "4":
                        nums.four(size);
                        break;
                    case "5":
                        nums.five(size);
                        break;
                    case "6":
                        nums.six(size);
                        break;
                    case "7":
                        nums.seven(size);
                        break;
                    case "8":
                        nums.eight(size);
                        break;
                    case "9":
                        nums.nine(size);
                        break;
                    case "0":
                        nums.zero(size);
                        break;
                }
            }
        }
    }
}