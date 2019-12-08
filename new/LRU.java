import java.util.Scanner;
import java.util.StringTokenizer;

public class LRU {
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
		
		System.out.println("Faults: " + lru(referenceStringBuilder.toString(), frames));
		
		input.close();
    }

    public static int lru(String reference_string, int frames) {
		int faults = 0;
		int[] array = new int [frames];
		int[] age = new int [frames];

		for(int i = 0; i < frames; i++){			
			array[i] = -1;							
													
			age[i] = 0;
		}

		StringTokenizer tok = new StringTokenizer(reference_string);

		while(tok.hasMoreTokens()){  // 1 2 32 2 3

			for (int i = 0; i < frames; i++){
				age[i]++;
			}

			int value = Integer.parseInt(tok.nextToken());

			if (!(isInFrames(value, frames, array))){
				faults++;
				int index = findMax(age);
				array[index] = value;
				age[index] = 0;
			}
			else{
				for (int i = 0; i < frames; i++){
					if (array[i] == value){
						age[i] = 0;
					}
				}
			}
		}
		return faults;
	}

	public static boolean isInFrames(int value, int frames, int[] array) {

		for (int i = 0; i < frames; i++){
			if (array[i] == value){
				return true;
			}
		}
		return false;
	}

	public static int findMax(int[] arr) {
		int idx = 0, maxValue = 0;

		for (int i = 0; i < arr.length; i++){
			if(arr[i] > maxValue){
				maxValue = arr[i];
				idx = i;
			}
		}
		return idx;
	}
}