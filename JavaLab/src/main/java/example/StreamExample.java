package example;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class StreamExample {
    public static void main(String[] args) {
        Path path = Paths.get(".");
        try {
            Stream<Path> list = Files.list(path);
            list.forEach(System.out::println);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}