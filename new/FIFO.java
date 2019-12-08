import java.util.Scanner;
import java.util.StringTokenizer;

public class FIFO {
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.println("Enter number of frames:");
		int frames = input.nextInt();
		input.nextLine();

		System.out.println("Enter reference string (Spaced):");
		String[] strings = input.nextLine().split(" ");
		
		StringBuilder referenceStringBuilder = new StringBuilder();
		
		for (String string : strings) {
			referenceStringBuilder.append(string).append(" ");
		}
		
		System.out.println("Faults: " + fifo(referenceStringBuilder.toString(), frames));
		
		input.close();
    }

    public static int fifo(String reference_string, int frames) {
		int faults = 0;

		int[] queue = new int [frames];

		for(int i = 0; i < frames; i++) {			
			queue[i] = -1;
		}

		int pointer = 0;

		StringTokenizer tok = new StringTokenizer(reference_string);

		while(tok.hasMoreTokens()) {
			int value = Integer.parseInt(tok.nextToken());

			if (!(isInFrames(value, frames, queue))) {
				faults++;
				queue[pointer] = value;
				pointer = (pointer+1)%frames;
			}
		}
		return faults;
    }
    
    public static boolean isInFrames(int value, int frames, int[] queue) {

		for (int i = 0; i < frames; i++) {
			if (queue[i] == value) {
				return true;
			}
		}
		return false;
	}
}