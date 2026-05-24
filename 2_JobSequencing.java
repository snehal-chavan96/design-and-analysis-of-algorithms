import java.util.Scanner;

public class JobSequencing {
    private static class Job {
        char id;
        int deadline;
        int profit;

        Job(char id, int deadline, int profit) {
            this.id = id;
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    private Job[] job = new Job[100];
    private int n;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of jobs: ");
        n = sc.nextInt();

        System.out.println("\nEnter Job ID, Deadline and Profit:");

        for (int i = 0; i < n; i++) {
            char id = sc.next().charAt(0);
            int deadline = sc.nextInt();
            int profit = sc.nextInt();
            job[i] = new Job(id, deadline, profit);
        }
    }

    public void sortJobs() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (job[i].profit < job[j].profit) {
                    Job temp = job[i];
                    job[i] = job[j];
                    job[j] = temp;
                }
            }
        }
    }

    public void sequenceJobs() {
        sortJobs();

        int maxDeadline = 0;

        // Find maximum deadline
        for (int i = 0; i < n; i++) {
            if (job[i].deadline > maxDeadline) {
                maxDeadline = job[i].deadline;
            }
        }

        char[] slot = new char[maxDeadline];

        // Initialize slots
        for (int i = 0; i < maxDeadline; i++) {
            slot[i] = '-';
        }

        int totalProfit = 0;

        // Assign jobs
        for (int i = 0; i < n; i++) {
            for (int j = job[i].deadline - 1; j >= 0; j--) {
                if (slot[j] == '-') {
                    slot[j] = job[i].id;
                    totalProfit += job[i].profit;
                    break;
                }
            }
        }

        System.out.println("\nSelected Job Sequence:");

        for (int i = 0; i < maxDeadline; i++) {
            System.out.print(slot[i] + " ");
        }

        System.out.println("\n\nMaximum Profit = " + totalProfit);
    }

    public static void main(String[] args) {
        JobSequencing j = new JobSequencing();
        j.getData();
        j.sequenceJobs();
    }
}
