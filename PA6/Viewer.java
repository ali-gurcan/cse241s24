import java.util.ArrayList;

public class Viewer extends Observer {
    // Constructor
    public Viewer() {
        // Initializing the playlist
        list = new ArrayList<Data>(); 
    }

    // Set the subject being observed
    public void set_subject(Dataset newSubject) {
        // Assign the observed subject
        subject = newSubject; 
        // Add this observer to the subject's list of observers
        subject.add_observer(this); 
    }

    // Update the viewer with new data lists
    public void update(ArrayList<Data> newPlayer, ArrayList<Data> newViewer) {
        list.clear(); // Clear the current playlist

        // Fill the playlist with new data from the dataset
        list.addAll(newViewer); 

        // If there is no current data, assign the first data in the playlist as current
        if (!newViewer.contains(current_data)) {
            if (!list.isEmpty()) {
                current_data = list.get(0);
            } else {
                // Set current_data to a default value
                // Replace this with your default value
                current_data = new Data(); 
            }
        }
    }

    // Stop observing the subject and clear the play list
    public void clean() {
        subject = null; // Set the observed subject to null
        list.clear(); // Clear the current playlist
    }

    // Show the list of non-playable items
    public void show_list() {
        if (this.subject == null)
            System.out.println("Viewer is not found."); // Viewer can't receive the list
        else if (list.size() == 0)
            System.out.println("List is empty."); // The list is empty
        else {
            // Otherwise, print the non-playable items in the playlist
            for (Data n : list) {
                if (n instanceof Non_playable)
                    ((Non_playable) n).info(); // Print information about the non-playable item
            }
        }
    }

    // Get the currently viewed non-playable item
    public Non_playable currently_viewing() {
        return (Non_playable) current_data; // Return the currently viewed non-playable item
    }

    // Move to the next item of the specified type
    public void next(String type) {
        int new_index = -1; // Initialize the new index

        // Find the index of the next item of the specified type in the playlist
        for (int i = 0; i < list.size(); i++) {
            if (current_data.get_name() == list.get(i).get_name()) {
                for (int j = i + 1; j < list.size(); j++) {
                    if (list.get(j) instanceof Visual && type == "image") {
                        new_index = j;
                        break;
                    } else if (list.get(j) instanceof Non_visual && type == "text") {
                        new_index = j;
                        break;
                    }
                }
            }
        }

        // Assign the current data to the next item of the specified type
        if (new_index == -1) {
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i) instanceof Visual && type == "image") {
                    current_data = list.get(i);
                    break;
                } else if (list.get(i) instanceof Non_visual && type == "text") {
                    current_data = list.get(i);
                    break;
                }
            }
        } else
            current_data = list.get(new_index);
    }

    // Move to the previous item of the specified type
    public void previous(String type) {
        int new_index = -1; // Initialize the new index

        // Find the index of the previous item of the specified type in the playlist
        for (int i = 0; i < list.size(); i++) {
            if (current_data.get_name() == list.get(i).get_name()) {
                for (int j = i - 1; j >= 0; j++) {
                    if (list.get(j) instanceof Visual && type == "image") {
                        new_index = j;
                        break;
                    } else if (list.get(j) instanceof Non_visual && type == "text") {
                        new_index = j;
                        break;
                    }
                }
            }
        }

        // Assign the current data to the previous item of the specified type
        if (new_index == -1) {
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i) instanceof Visual && type == "image") {
                    current_data = list.get(i);
                    break;
                } else if (list.get(i) instanceof Non_visual && type == "text") {
                    current_data = list.get(i);
                    break;
                }
            }
        } else
            current_data = list.get(new_index);
    }

    // Control if the current data is removed
    public void controlRemoved(Data checkDelete) {
        if (current_data == checkDelete) {
            if (checkDelete instanceof Visual)
                this.next("image"); // Move to the next visual item
            else if (checkDelete instanceof Non_visual)
                this.next("text"); // Move to the next non-visual item
        }
    }

    // Override method to return the currently playing item
    @Override
    public Playable currently_playing() {
        return null; // Currently playing item is not applicable for the Viewer
    }
}
