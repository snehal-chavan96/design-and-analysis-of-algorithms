import java.util.Scanner;

public class ActivitySelection {
    private static class Activity {
        int start;
        int finish;

        Activity(int start, int finish) {
            this.start = start;
            this.finish = finish;
        }
    }

    private Activity[] act = new Activity[100];
    private int n;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of activities: ");
        n = sc.nextInt();

        System.out.println("\nEnter start and finish times:");

        for (int i = 0; i < n; i++) {
            System.out.println("\nActivity " + (i + 1) + ":");
            System.out.print("Start time: ");
            int start = sc.nextInt();
            System.out.print("Finish time: ");
            int finish = sc.nextInt();
            act[i] = new Activity(start, finish);
        }
    }

    public void sortActivities() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (act[i].finish > act[j].finish) {
                    Activity temp = act[i];
                    act[i] = act[j];
                    act[j] = temp;
                }
            }
        }
    }

    public void selectActivities() {
        sortActivities();

        System.out.println("\nSelected Activities:");

        int i = 0;
        System.out.println("Activity 1 (" + act[i].start + "," + act[i].finish + ")");

        for (int j = 1; j < n; j++) {
            if (act[j].start >= act[i].finish) {
                System.out.println("Activity " + (j + 1) + " (" + act[j].start + "," + act[j].finish + ")");
                i = j;
            }
        }
    }

    public static void main(String[] args) {
        ActivitySelection a = new ActivitySelection();
        a.getData();
        a.selectActivities();
    }
}
