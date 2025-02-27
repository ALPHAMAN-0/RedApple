import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FrameIntro extends JPanel implements KeyListener {
    int borderWidth = 800;
    int borderHeight = 450;
    
    private JLabel userLabel, passLabel;
    private JTextField userField;
    private JPasswordField passField; 
    private JButton loginBtn, newFrameBtn;
    private ImageIcon bgImage;
    private JLabel imageLabel;

    public FrameIntro() {
        setPreferredSize(new Dimension(borderWidth, borderHeight));
        setLayout(null);
        setBackground(new Color(230, 230, 250));
        
        // Add username components
        userLabel = new JLabel("Username:");
        userLabel.setBounds(250, 100, 100, 30);
        userLabel.setForeground(Color.BLUE);
        add(userLabel);
        
        userField = new JTextField();
        userField.setBounds(350, 100, 150, 30);
        add(userField);

        // Add password components  
        passLabel = new JLabel("Password:");
        passLabel.setBounds(250, 150, 100, 30);
        passLabel.setForeground(Color.BLUE);
        add(passLabel);
        
        passField = new JPasswordField();
        passField.setBounds(350, 150, 150, 30);
        add(passField);

        // Add buttons
        loginBtn = new JButton("Login");
        loginBtn.setBounds(300, 200, 80, 30);
        loginBtn.setBackground(Color.GREEN);
        loginBtn.addActionListener(e -> {
            String username = userField.getText();
            JOptionPane.showMessageDialog(this, "Welcome " + username);
        });
        add(loginBtn);

        newFrameBtn = new JButton("New Frame");
        newFrameBtn.setBounds(400, 200, 100, 30); 
        newFrameBtn.setBackground(Color.CYAN);
        newFrameBtn.addActionListener(e -> openNewFrame());
        add(newFrameBtn);

        // Add image
        bgImage = new ImageIcon("./Cry.png");
        Image scaledImg = bgImage.getImage().getScaledInstance(200, 200, Image.SCALE_SMOOTH);
        imageLabel = new JLabel(new ImageIcon(scaledImg));
        imageLabel.setBounds(550, 100, 200, 200);
        add(imageLabel);

        setFocusable(true);
        addKeyListener(this);
    }

    private void openNewFrame() {
        NewWindow newWindow = new NewWindow();
        newWindow.setVisible(true);
    }

    @Override
    public void keyTyped(KeyEvent e) {}
    @Override 
    public void keyPressed(KeyEvent e) {}
    @Override
    public void keyReleased(KeyEvent e) {}
}