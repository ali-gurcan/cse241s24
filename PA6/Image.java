public class Image extends Data implements Visual, Non_playable {
	// Constructor
	public Image(String newName, String newDimension, String newOther) {
		super(newName, newDimension, newOther);
	}

	// function from interface
	@Override
	public void info() {
		System.out.printf("%s - ", get_name());
		System.out.printf("%s - ", get_dd());
		System.out.printf("%s\n", get_other());
	}

 
}