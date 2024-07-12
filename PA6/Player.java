import java.util.ArrayList;

public class Player extends Observer {
    // Constructor
    public Player() {
        // Initializing the playlist
        list = new ArrayList<Data>();
    }

    // This function is defined in the abstract class Observer
    public void set_subject(Dataset newSubject) {
        // Set the subject being observed
        subject = newSubject;
        // Add this observer to the subject's observer list
        subject.add_observer(this);
    }

    // Update the viewer with new data lists
    public void update(ArrayList<Data> newPlayer, ArrayList<Data> newViewer) {
        list.clear(); // Clear the current playlist

        list.addAll(newPlayer); // Fill the playlist with new data from the dataset

        // If there is no current data, assign the first data in the playlist as current
        if (!newPlayer.contains(current_data)) {
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
        subject = null;
        list.clear();
    }

    // Display the play list
    public void show_list() {
        // If the player is not set to a subject
        if (this.subject == null)
            System.out.println("Player is not found.");
        // If the play list is empty
        else if (list.size() == 0)
            System.out.println("List is empty.");
        // Otherwise, print the play list
        else {
            for (Data n : list) {
                if (n instanceof Playable)
                    ((Playable) n).info();
            }
        }
    }

    // Return the currently playing item
    public Playable currently_playing() {
        return (Playable) current_data;
    }

    // Go to the next item of the specified type in the play list
    public void next(String type) {
        int new_index = -1;
        for (int i = 0; i < list.size(); i++) {
            // Find the current data in the play list
            if (current_data.get_name() == list.get(i).get_name()) {
                // Find the next item of the same type as the current data
                for (int j = i + 1; j < list.size(); j++) {
                    if (list.get(j) instanceof Visual && type.equals("video")) {
                        new_index = j;
                        break;
                    } else if (list.get(j) instanceof Non_visual && type.equals("audio")) {
                        new_index = j;
                        break;
                    }
                }
            }
        }

        // If no next item of the same type, go to the first item of that type
        if (new_index == -1) {
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i) instanceof Visual && type.equals("video")) {
                    current_data = list.get(i);
                    break;
                } else if (list.get(i) instanceof Non_visual && type.equals("audio")) {
                    current_data = list.get(i);
                    break;
                }
            }
        } else {
            current_data = list.get(new_index);
        }
    }

    // Go to the previous item of the specified type in the play list
    public void previous(String type) {
        int new_index = -1;
        for (int i = 0; i < list.size(); i++) {
            // Find the current data in the play list
            if (current_data.get_name() == list.get(i).get_name()) {
                // Find the previous item of the same type as the current data
                for (int j = i - 1; j >= 0; j--) {
                    if (list.get(j) instanceof Visual && type.equals("video")) {
                        new_index = j;
                        break;
                    } else if (list.get(j) instanceof Non_visual && type.equals("audio")) {
                        new_index = j;
                        break;
                    }
                }
            }
        }

        // If no previous item of the same type, go to the first item of that type
        if (new_index == -1) {
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i) instanceof Visual && type.equals("video")) {
                    current_data = list.get(i);
                    break;
                } else if (list.get(i) instanceof Non_visual && type.equals("audio")) {
                    current_data = list.get(i);
                    break;
                }
            }
        } else {
            current_data = list.get(new_index);
        }
    }

    // Check if the current data was removed
    public void controlRemoved(Data del) {
        if (current_data == del) {
            if (del instanceof Visual)
                this.next("video");
            else if (del instanceof Non_visual)
                this.next("audio");
        }
    }

    @Override
    public Non_playable currently_viewing() {
        return null;
    }
}
