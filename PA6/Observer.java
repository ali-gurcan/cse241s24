import java.util.ArrayList;

// Abstract class for observers: Player and Viewer
public abstract class Observer {

    // Playlist
    protected ArrayList<Data> list;

    // Observed subject
    protected Dataset subject;

    // Currently playing data from the playlist
    protected Data current_data;

    // Function to observe the observer to the subject
    public abstract void set_subject(Dataset subject);

    // Function to update the playlist
    public abstract void update(ArrayList<Data> newPlayer, ArrayList<Data> newViewer);

    // Function to clean the playlist and quit from the subject when the observer is removed from the subject
    public abstract void clean();

    // Function to show all data in the playlist
    public abstract void show_list();

    // Function to return the currently playing data in the playlist
    public abstract Playable currently_playing();

    // Function to return the currently viewing non-playable data in the playlist
    public abstract Non_playable currently_viewing();

    // Function to move to the next data in the playlist
    public abstract void next(String type);

    // Function to move to the previous data in the playlist
    public abstract void previous(String type);

    // If a data is removed, move to the next data of the same type
    public abstract void controlRemoved(Data isDeleted);
}