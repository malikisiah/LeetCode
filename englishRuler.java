class englishRuler{

    private static String indent = "";


    public static void main(String[]args){
        drawRuler(5,4);
    }

    public static void drawRuler(int nInches, int majorLength) {

        drawLine(majorLength, 0);
        for (int j = 1; j <= nInches; j++) {
          drawInterval(majorLength - 1);
          drawLine(majorLength, j);
        }
      }


      private static void drawInterval(int centralLength) {
         indent += "  ";

        if (centralLength >= 1) {
          drawInterval(centralLength - 1);
          drawLine(centralLength);
          drawInterval(centralLength - 1);
        }
        indent = indent.substring(2);
      }


      private static void drawLine(int tickLength, int tickLabel) {
        indent += "  ";

        for (int j = 0; j < tickLength; j++)
          System.out.print("-");
        if (tickLabel >= 0)
          System.out.print(" " + tickLabel);
        System.out.print("\n");
        indent = indent.substring(2);
      }

      private static void drawLine(int tickLength) {
        drawLine(tickLength, -1);
      }
}