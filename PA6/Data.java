class Data {
	// superclass for auido,image,video and text
	// name
	private String name;
	// it is dimension for video and image,duration for audio
	private String dimension_duration;
	// other info
	private String other_info;

	public Data() {}

	public Data(String newName, String newOther) {
		name = newName;
		other_info = newOther;
	}

	public Data(String newName, String newD, String newOther) {
		name = newName;
		dimension_duration = newD;
		other_info = newOther;
	}

	public String get_name() {
		return name;
	}

	public String get_dd() {
		if (dimension_duration == null) {
			String temp = "";
			return temp;
		}
		return dimension_duration;
	}

	public String get_other() {
		return other_info;
	}

}