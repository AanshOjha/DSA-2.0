public class Patterns {
    public static void main(String[] args) {
        pattern6(5);
    }

    static void pattern1(int n) {
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<= n-i+1; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    static void pattern2(int n) {
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<= n-i+1; j++) {
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }

    static void pattern3(int n) {
        for (int i = 1; i <=n; i++) {
            // for spaces
            for (int j = 1; j <=(n-i); j++) {
                System.out.print(" ");
            }
            // for stars
            for (int k = 1; k <= (i*2)-1; k++) {
                System.out.print("*");
            }
            System.out.println();
        }

        // If you want spaces between stars, then j <= 2*(n-i)
    }

    static void pattern4(int n) {
        for (int i = 1; i <=n; i++) {
            // for spaces
            for (int j = 1; j <=i-1; j++) {
                System.out.print(" ");
            }
            // for stars
            for (int k = 1; k <= (n-i)*2 + 1; k++) {
                System.out.print("*");
            }
            System.out.println();
        }

        // If you want spaces between stars, then j <= 2*(n-i)
    }

    static void pattern5(int n) {
        for (int i = 1; i <= n; i++) {
            // For upper left triangle
            for (int j = 1; j <= n-i+1; j++) {
                System.out.print("*");
            }

            // For upper spaces
            for (int j = 1; j <= 2*(i-1); j++) {
                System.out.print(" ");
            }

            // For upper right triangle
            for (int j = 1; j <= n-i+1; j++) {
                System.out.print("*");
            }
            System.out.println();            
        }
        for (int i = 1; i <= n; i++) {
            // For lower left triangle
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }

            // For lower spaces
            for (int j = 1; j <= 2*(n-i); j++) {
                System.out.print(" ");
            }

            // For lower right triangle
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

    static void pattern6(int n) {
        for (int i = 1; i <= n; i++) {
            // For upper left triangle
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }

            // For upper spaces
            for (int j = 1; j <= 2*(n-i); j++) {
                System.out.print(" ");
            }

            // For upper right triangle
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = 1; i <= n; i++) {
            // For lower left triangle
            for (int j = 1; j <= n-i; j++) {
                System.out.print("*");
            }

            // For lower spaces
            for (int j = 1; j <= 2*i; j++) {
                System.out.print(" ");
            }

            // For lower right triangle
            for (int j = 1; j <= n-i; j++) {
                System.out.print("*");
            }
            System.out.println();            
        }
        
    }
}