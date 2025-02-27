import javax.swing.JFrame;

public class App {
    public static void main(String[] args) throws Exception {
        int borderWidth = 800;
        int borderHeight = 450;

        JFrame frame = new JFrame("Log In Form");
        frame.setSize(borderWidth, borderHeight);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);  

        FrameIntro frameintro = new FrameIntro();
        frame.add(frameintro);
        frame.pack();
        frameintro.requestFocus();   
        frame.setVisible(true); 

    }
}
