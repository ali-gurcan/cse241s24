public class Video extends Data implements Visual, Playable {
	// Constructor
	public Video(String newName, String dimension, String newOther) {
		super(newName, dimension, newOther);
	}

	// function from interface
	@Override
	public void info() {
		System.out.printf("%s - ", get_name());
		System.out.printf("%s - ", get_dd());
		System.out.printf("%s\n", get_other());
	}
 
}