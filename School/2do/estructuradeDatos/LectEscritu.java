import java.io.*;

public class LectEscritu {
    public static void main(String[] args) {
        // Escribir
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("text.txt"))) {
            writer.write("Lorem ipsum dolor sit amet,\n consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. \n " + 
            "Ut enim ad minim veniam, quis nostrud exercitation\n ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. \n "  + 
            "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
        } catch (IOException e) {
            System.out.println("Error write archivo: " + e.getMessage());
        }

        // Leer
        try (BufferedReader reader = new BufferedReader(new FileReader("text.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("Error read archivo: " + e.getMessage());
        }
    }
}