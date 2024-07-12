public class Audio extends Data implements Non_visual, Playable {

	// constructor
	public Audio(String newName, String newDuration, String newOther) {
		super(newName, newDuration, newOther);
	}

	// function from interface
	@Override
	public void info() {
		System.out.printf("%s - ", get_name());
		System.out.printf("%s - ", get_dd());
		System.out.printf("%s\n", get_other());

	}

}