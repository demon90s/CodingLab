import java.io.*;

class Employee implements java.io.Serializable
{
    public String name;
    public String address;
    public transient int SSN; // 短暂的，不会被序列化
    public int number;

    public void mailCheck() {
        System.out.println("Mailing a check to " + name + " " + address);
    }
}

public class SerializeExample {

    static void Serialize() {
        Employee e = new Employee();
        e.name = "Diwen";
        e.address = "Guangzhou";
        e.SSN = 11122333;
        e.number = 101;

        try {
            FileOutputStream fileOut = new FileOutputStream("./employ.ser");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(e);
            out.close();
            fileOut.close();

            System.out.println("Serialized data is saved in ./employ.ser");
        } catch(IOException i) {
            i.printStackTrace();
        }
    }

    static void Deserialize() {
        Employee e = null;
        try {
            FileInputStream fileIn = new FileInputStream("./employ.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);
            e = (Employee) in.readObject();
            in.close();
            fileIn.close();
        } catch(IOException i) {
            i.printStackTrace();
            return;
        } catch(ClassNotFoundException c) {
            System.out.println("Employee class not found");
            c.printStackTrace();
            return;
        }

        System.out.println("Deserialized Employee...");
        System.out.println("Name: " + e.name);
        System.out.println("Address: " + e.address);
        System.out.println("SSN: " + e.SSN);
        System.out.println("Number: " + e.number);
    }

    public static void main(String[] args) {
        //Serialize();
        Deserialize();
    }
}