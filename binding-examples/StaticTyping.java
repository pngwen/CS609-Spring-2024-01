class StaticTyping {
  public static void main(String[] args) {
    int x;
    double y;
  
    // try to do integer to double coercion (Type widening)
    x = 1;
    y = x;
    System.out.println(y);
  
    // try to do double to integer coercion (Type narrowing)
    //   - we Must do this explicitly in java
    //   - truncates the value
    y = 4.999999;
    x = (int) y;
    System.out.println(x);
  }
}