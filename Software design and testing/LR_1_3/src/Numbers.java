public class Numbers {
    public void one(int size) {
        int col = size + 2;
        int line = size + 3;
        int centerCol = (int)Math.floor(col / 2);
        int centerLine = (int)Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i == 0 || i == centerLine || i == line - 1) {
                for (int j = 0; j < col; j++) {
                        System.out.print(" ");
                }
                System.out.print("\n");
            } else {
                for (int j = 0; j < col; j++) {
                    if (j == centerCol) {
                        System.out.print("|");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void two(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int)Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i == 0 || i == center || i == line - 1) {
                for (int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("-");
                    }
                }
                System.out.print("\n");
            } else {
                for (int j = 0; j < col; j++) {
                    if(i < center) {
                        if(j == col - 1) {
                            System.out.print("|");
                        } else {
                            System.out.print(" ");
                        }
                    } else {
                        if(j == 0) {
                            System.out.print("|");
                        } else {
                            System.out.print(" ");
                        }
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void three(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int)Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i == 0 || i == center || i == line - 1) {
                for (int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("-");
                    }
                }
                System.out.print("\n");
            } else {
                for (int j = 0; j < col; j++) {
                    if(j == col - 1) {
                        System.out.print("|");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void four(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int)Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i < 2 || i > line - 3) {
                for (int j = 0; j < col; j++) {
                    System.out.print(" ");
                }
                System.out.print("\n");
            } else {
                for (int j = 0; j < col; j++) {
                    if (i < center) {
                        if (j == 0 || j == col - 1) {
                            System.out.print("|");
                        }
                        else {
                            System.out.print(" ");
                        }
                    }
                    else if (i == center) {
                        System.out.print("-");
                    }
                    else {
                        if (j == col - 1) {
                            System.out.print("|");
                        }
                        else {
                            System.out.print(" ");
                        }
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void five(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int)Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i == 0 || i == center || i == line - 1) {
                for (int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("-");
                    }
                }
                System.out.print("\n");
            } else {
                for (int j = 0; j < col; j++) {
                    if(i < center) {
                        if(j == 0) {
                            System.out.print("|");
                        } else {
                            System.out.print(" ");
                        }
                    } else {
                        if(j == col - 1) {
                            System.out.print("|");
                        } else {
                            System.out.print(" ");
                        }
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void six(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int)Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i == 0 || i == center || i == line - 1) {
                for (int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("-");
                    }
                }
                System.out.print("\n");
            } else {
                for(int j = 0; j < col; j++) {
                    if (i < center) {
                        if (j == 0) {
                            System.out.print("|");
                        } else {
                            System.out.print(" ");
                        }
                    } else {
                        if (j == 0) {
                            System.out.print("|");
                        } else if (j == col - 1) {
                            System.out.print("|");
                        } else {
                            System.out.print(" ");
                        }
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void seven(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int)Math.floor(line / 2);

        for (int i = 0; i < line; i++) {
            if (i == 0) {
                for (int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("-");
                    }
                }
                System.out.print("\n");
            } else if (i == center) {
                for (int j = 0; j < col; j++) {
                    System.out.print(" ");
                }
                System.out.print("\n");
            } else {
                for (int j = 0; j < col; j++) {
                    if (j == col - 1) {
                        System.out.print("|");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void eight(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int)Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i == 0 || i == center || i == line - 1) {
                for (int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("-");
                    }
                }
                System.out.print("\n");
            } else {
                for(int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print("|");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void nine(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int) Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i == 0 || i == center || i == line - 1) {
                for (int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("-");
                    }
                }
                System.out.print("\n");
            } else {
                for(int j = 0; j < col; j++) {
                    if (i < center) {
                        if (j == 0 || j == col - 1) {
                            System.out.print("|");
                        } else {
                            System.out.print(" ");
                        }
                    } else {
                        if (j == col - 1) {
                            System.out.print("|");
                        } else {
                            System.out.print(" ");
                        }
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public void zero(int size) {
        int col = size + 2;
        int line = size + 3;
        int center = (int) Math.floor(line / 2);

        for(int i = 0; i < line; i++) {
            if (i == 0 || i == line - 1) {
                for (int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("-");
                    }
                }
                System.out.print("\n");
            } else if (i == center) {
                for (int j = 0; j < col; j++) {
                    System.out.print(" ");
                }
                System.out.print("\n");
            } else {
                for(int j = 0; j < col; j++) {
                    if (j == 0 || j == col - 1) {
                        System.out.print("|");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.print("\n");
            }
        }
    }
}