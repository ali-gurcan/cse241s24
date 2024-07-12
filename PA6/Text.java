public class Text extends Data implements Non_visual, Non_playable {
	// Construct
	public Text(String newName, String newOther) {
		super(newName, newOther);
	}

	// function from interface
	@Override
	public void info() {
		System.out.printf("%s - ", get_name());
		System.out.printf("%s\n", get_other());
	}

}