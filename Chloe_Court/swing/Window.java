package swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class Window extends JFrame {
    private JTextArea readArea;
    private JTextField writeArea;
    private JButton searchButton, playButton, quitButton;
    private JMenuBar menuBar;
    private JMenu menu;
    private JToolBar toolBar;
    private Client client;  

    /**
     * Constructeur
     * Crée la fenêtre principale
     * Ajoute les composants (boutons et menu déroulant et leurs actions respectives)
     */
    public Window() {
        super("Main Window");
        connectClient();
        System.setProperty("apple.laf.useScreenMenuBar", "true");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel northPanel = new JPanel(new BorderLayout());

        // Création de la zone de texte
        readArea = new JTextArea(30, 60);
        readArea.setLineWrap(true); // Activation du retour automatique à la ligne
        readArea.setWrapStyleWord(true); 
        writeArea = new JTextField();
        JScrollPane scrollPane = new JScrollPane(readArea);

        // Création des boutons et des actions
        Action actionSearchButton = new AbstractAction("play") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String request = "play " + writeArea.getText();
                System.out.println("Request: " + request);
                String response = client.send(request);
                System.out.println("Response: " + response);
                readArea.append(response + "\n");
                writeArea.setText("");
            }
        };

        Action actionPlayButton = new AbstractAction("Search and Display") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String request = "display " + writeArea.getText();
                System.out.println("Request: " + request);
                String response = client.send(request);
                System.out.println("Response: " + response);
                readArea.append(response + "\n");
                writeArea.setText("");
            }
        };

        Action actionQuitBouton = new AbstractAction("Quit") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };

        searchButton = new JButton(actionSearchButton);
        playButton = new JButton(actionPlayButton);
        quitButton = new JButton(actionQuitBouton);

        // Création du menu déroulant
        menuBar = new JMenuBar();
        menu = new JMenu("Menu");
        menu.add(new JMenuItem(actionSearchButton));
        menu.add(new JMenuItem(actionPlayButton));
        menu.add(new JMenuItem(actionQuitBouton));
        menuBar.add(menu);

        northPanel.add(menuBar, BorderLayout.NORTH);

        // Création de la barre d'outils
        toolBar = new JToolBar();
        toolBar.add(searchButton);
        toolBar.add(playButton);

        northPanel.add(toolBar, BorderLayout.SOUTH);

        add(northPanel, BorderLayout.NORTH);

        // Ajout de la zone de texte
        add(scrollPane, BorderLayout.CENTER);

        // Adapter la taille de la fenêtre aux composants
        pack();
        // Rendre la fenêtre visible
        setVisible(true);
    }

    /**
     * Connecte le client au serveur
     */
    public void connectClient() {
        String host = "localhost";
        int port = 3331;
        try {
            client = new Client(host, port);
        }
        catch (Exception e) {
            System.err.println("Client: Couldn't connect to "+host+":"+port);
            System.exit(1);
        }
        System.out.println("Client connected to "+host+":"+port);
    }
    /**
     * Méthode principale
     * Crée une fenêtre
     */
    public static void main(String[] args) {
        // Pour les utilisateurs de MacOSX
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Window();
            }
        });
    }

}
