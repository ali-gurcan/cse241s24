import java.util.ArrayList;

// This class represents a subject that can be observed by observers.
// Observers can receive this class's list and be informed when it changes, updating themselves accordingly.
public class Dataset {
	private ArrayList<Data> playable_array; // List of playable data
	private ArrayList<Data> non_playable_array; // List of non-playable data
	private ArrayList<Observer> observers; // List of observers

	// Getters
	public ArrayList<Data> getPlayable_array() {
		return playable_array;
	}

	public ArrayList<Data> getNon_playable_array() {
		return non_playable_array;
	}

	public ArrayList<Observer> getObservers() {
		return observers;
	}

	// Constructor
	public Dataset() {
		playable_array = new ArrayList<Data>();
		non_playable_array = new ArrayList<Data>();
		observers = new ArrayList<Observer>();
	}

	// Function to register an observer to the dataset
	public void register(Observer observer) {
		// Add observer to the list
		observers.add(observer); 
		// Make the observer observe this dataset
		observer.set_subject(this);
		// Send arrays of data to the observer
		observer.update(playable_array, non_playable_array); 
	}

	// Function to add an observer to the list of observers
	public void add_observer(Observer observer) {
		// Add observer to the list
		observers.add(observer); 
	}

	// Function to remove an observer from the list of observers
	public void remove_observer(Observer observer) {
		// Remove observer from the list
		observers.remove(observer); 
		// The observer quits from observing this dataset and clears its current playlist
		observer.clean(); 
	}

	// Function to notify all observers when the list changes
	public void notify_observer() {
		// Loop through all observers
		for (Observer observer : observers) {
			// Call the observer's list setter
			observer.update(playable_array, non_playable_array);
		}
	}

	// Function to add data to the dataset's ArrayLists
	public void add(Data newData) {
		if (newData instanceof Playable)
			playable_array.add(newData); // Add playable data to the list
		else
			non_playable_array.add(newData); // Add non-playable data to the list

		notify_observer(); // Notify all observers to update themselves
	}

	// Function to remove data from the dataset's ArrayLists
	public <T> void remove(T removeObj) {
		// Check if the data is in the playable ArrayList and remove it
		if (removeObj instanceof Playable) {
			for (int i = 0; i < playable_array.size(); i++) {
				if (playable_array.get(i) == removeObj) {
					playable_array.remove(i);
				}
			}
		}

		// Check if the data is in the non-playable ArrayList and remove it
		if (removeObj instanceof Non_playable) {
			for (int i = 0; i < non_playable_array.size(); i++) {
				if (non_playable_array.get(i) == removeObj) {
					non_playable_array.remove(i);
				}
			}
		}

		// Control if any observer's current playing data is removed
		for (Observer observer : observers) {
			observer.controlRemoved((Data) removeObj);
		}

		notify_observer(); // Notify all observers to update themselves
	}
}
