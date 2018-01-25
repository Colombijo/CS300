import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class CourseSchedule {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter quarter: ");
        String quarter = scan.next();
        System.out.print("Enter year: ");
        String year = scan.next();
        System.out.print("Enter initial for the program: ");
        String initial = scan.next();
        System.out.println();
        System.out.println("Programs:");
        String extension = "https://www.bellevuecollege.edu/classes/" + quarter + year;

        URL second = new URL(extension);
        BufferedReader in = new BufferedReader(new InputStreamReader(second.openStream()));
        String inputLine = "";
        String text = "";
        while ((inputLine = in.readLine()) != null) {
            text += inputLine + "\n";
        }
        in.close();

        Pattern pattern = Pattern.compile("<a\\shref=\"\\Sclasses\\S" + quarter + year + ".*\">" + initial + "(.*)</a>\\s*(.*)\\s");
        Matcher matcher = pattern.matcher(text);

        while (matcher.find()) {
            System.out.print(initial + matcher.group(1));
            System.out.println(" " + matcher.group(2));
        }

        System.out.println();
        System.out.print("Enter the program's name: ");
        String program = scan.next();
        System.out.println();
        System.out.print("Enter the course ID: ");
        String courseABV = scan.next();
        String courseNumber = scan.next();
        String courseId = courseABV + " " + courseNumber;
        System.out.println();
        System.out.println(program + " courses in " + quarter + " " + year);
        System.out.println("==================================");
        String programSite = extension + "/" + courseABV;
        System.out.println(courseABV);

        URL courseSite = new URL(programSite);
        BufferedReader inTwo = new BufferedReader(new InputStreamReader(courseSite.openStream()));
        String courseInput = "";
        String courseText = "";
        while ((courseInput = inTwo.readLine()) != null) {
            courseText += courseInput + "\n";
        }
        inTwo.close();

        Pattern patternTwo = Pattern.compile("<a\\shref=\"/classes/All/" + program + "/" + courseNumber + "\">[\\s\\S]*?courseTitle\">(.*)</span>[\\s\\S]*?number:\\s</span>(.*)</span>[\\s\\S]*?SearchString.*\">(.*)</a>[\\s\\S]*?<span\\sclass=\"days\"[\\s\\S]*?\">\\s*(.*)\\s*");
        matcher = patternTwo.matcher(courseText);
        while (matcher.find()) {
            System.out.println("Code: " + courseId);
            System.out.println("Item#: " + matcher.group(2));
            System.out.println("Title: " + matcher.group(1));
            System.out.println("Instructor: " + matcher.group(3));
            System.out.println("Days: " + matcher.group(4));
            System.out.println();
        }
    }
}


