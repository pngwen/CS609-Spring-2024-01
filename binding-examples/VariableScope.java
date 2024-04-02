public class VariableScope {
  private static int x=12;
  
  public static void f() {
    int x;
    x = 5;
  }

  public static void main(String [] args) {
    int x = 1;

    System.out.println(x);
    f();
 //   {
 //     int x = 2;
 //   }
    System.out.println(x);
  
    /*for(int y=4; y<10; y++) {
      
    }
    System.out.println(y);
    */
  }
}