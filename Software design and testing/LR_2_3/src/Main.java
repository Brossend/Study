import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int scenario, authors, articles, erdos = 0;

        System.out.print("Введите номер сценария.\nВвод: ");
        scenario = in.nextInt();

        System.out.print("\nВведите количество статей.\nВвод: ");
        articles = in.nextInt();

        System.out.print("\nВведите количество авторов.\nВвод: ");
        authors = in.nextInt();

        String ArrayArticles [] = new String[articles];
        String ArrayAuthors [] = new String[authors];
        int ArrayScores [] = new int[authors];

        in.nextLine();

        for (int i = 0; i < articles; i++) {
            System.out.print("\nВведите " + (i + 1) + " статью.\nВвод: ");
            ArrayArticles[i] = in.nextLine();
        }

        for (int i = 0; i < authors; i++) {
            System.out.print("\nВведите " + (i + 1) + " автора.\nВвод: ");
            ArrayAuthors[i] = in.nextLine();
        }

        for (int i = 0; i < articles; i++) {
            String TempArticles [] = ArrayArticles[i].split("[,:]");

            for(String value: TempArticles) {
                if(value.equals("Erdos P.")) {
                    erdos = 1;
                    break;
                } else {
                    erdos = 0;
                }
            }

            for(int j = 0; j < TempArticles.length; j++) {
                for (int l = 0; l < authors; l++) {
                    if(ArrayAuthors[l].equals(TempArticles[j]) && erdos == 1) {
                        ArrayScores[l] = 1;
                    }
                }
            }
        }

        for(int i = 0; i < ArrayScores.length; i++) {
            if (ArrayScores[i] == 1) {
                for (int j = 0; j < articles; j++) {
                    String TempArticlesTwo [] = ArrayArticles[j].split("[,:]");

                    for(String value: TempArticlesTwo) {
                        if(value.equals(ArrayAuthors[i])) {
                            erdos = 2;
                            break;
                        } else {
                            erdos = 1;
                        }
                    }

                    for(int l = 0; l < TempArticlesTwo.length; l++) {
                        for (int k = 0; k < authors; k++) {
                            if(ArrayScores[k] != 1 && ArrayAuthors[k].equals(TempArticlesTwo[l]) && erdos == 2) {
                                ArrayScores[k] = 2;
                            }
                        }
                    }
                }
            }
        }

        System.out.println("\nScenario " + scenario);

        for(int i = 0; i < ArrayAuthors.length; i++) {
            if (ArrayScores[i] == 0) {
                System.out.println(ArrayAuthors[i] + " infinity");
            } else {
                System.out.println(ArrayAuthors[i] + " " + ArrayScores[i]);
            }
        }
    }
}