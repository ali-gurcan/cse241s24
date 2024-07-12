public class Main {
	public static void main(String[] args) {

		Dataset ds = new Dataset();

		//Create Player and Viewer instances
		Player p1 = new Player();
		Player p2 = new Player();
		Viewer v1 = new Viewer();
		Viewer v2 = new Viewer();
 
	
		ds.register(p1);
		ds.register(p2);
		ds.register(v1);
		ds.register(v2);

 		//Adding some items to the dataset
 		ds.add(new Image("image1", "50", "jpg"));
		ds.add(new Image("image2", "80", "png"));
		ds.add(new Image("image3", "100", "jpeg"));
		ds.add(new Image("image4", "240", "raw"));
		ds.add(new Image("image5", "300", "svg"));

		ds.add(new Audio("audio1", "10", "dolby atmos"));
		ds.add(new Audio("audio2", "2", "mp3"));
		ds.add(new Audio("audio3", "40", "hi-fi"));

		ds.add(new Video("video1", "200", "fhd"));
		ds.add(new Video("video2", "300", "2k"));
		ds.add(new Video("video3", "400", "4k"));

		ds.add(new Text("text1", "word"));
		ds.add(new Text("text2", "pdf"));
		ds.add(new Text("text3", "txt"));

		System.out.println("Player1 list:");
		p1.show_list();
		System.out.println("Player2 list:");
		p2.show_list();
		System.out.println("Viewer1 list:");
		v1.show_list();
		System.out.println("Viewer2 list:");
		v2.show_list();

		//Getting currently playing/viewing items for players and viewers
		Playable play1 = p1.currently_playing();
		Playable play2 = p2.currently_playing();
		Non_playable n_play1 = v1.currently_viewing();
		Non_playable n_play2 = v2.currently_viewing();

		// Display currently playing/viewing items
		System.out.println("-----------------------------");
		System.out.println("CURRENT PART");
		System.out.println("player1 current info:");
		play1.info();
		System.out.println("player2 current info");
		play2.info();
		System.out.println("viewer1 current info:");
		n_play1.info();
		System.out.println("viewer2 current info:");
		n_play2.info();
		System.out.println("-----------------------------");

		// Move to the next item in the respective media type for players and viewers
		p1.next("audio");// -->audio2

		p2.next("video");// video1
		p2.next("video");// video2
		p2.next("video");// -->video3

		v1.next("image");// image2
		v1.next("image");// -->image3

		v2.next("text");// -->text1

		//Updating currently playing/viewing items
		play1 = p1.currently_playing();// audio2
		play2 = p2.currently_playing();// video3
		n_play1 = v1.currently_viewing();// image3
		n_play2 = v2.currently_viewing(); // text1

		System.out.println("NEXT PART");
		System.out.println("player1 current info:");
		play1.info();
		System.out.println("player2 current info");
		play2.info();
		System.out.println("viewer1 current info:");
		n_play1.info();
		System.out.println("viewer2 current info:");
		n_play2.info();
		System.out.println("-----------------------------");

		System.out.println("PREVIOUS PART");
		System.out.println("player1 current info:");

		//Previous operations audio for player1, note the behavior when no more previous items
		p1.previous("audio");// audio2
		p1.previous("audio");// -->audio1
		p1.previous("audio");// -->audio1
		play1 = p1.currently_playing();
		play1.info();

		System.out.println("player2 current info:");
		// Go to the previous video for player2
		p2.previous("video");// -->video2
		play2 = p2.currently_playing();
		play2.info();

	
		System.out.println("-----------------------------");
		// first version of viewer1
		System.out.println("Viewer1 first version");
		v1.show_list();
		System.out.println("Viewer1 current after removing a visual from the list");
		ds.remove(n_play1);// image 3 is removed image4 will be shown
		n_play1 = v1.currently_viewing();
		n_play1.info();

		System.out.println("-----------------------------");
		System.out.println("Viewer1 current info after 4 times next");
		
		//Moving to the next text for viewer1 multiple times but it goes to first one
		v1.next("text");
		v1.next("text");
		v1.next("text");
		v1.next("text");
		n_play1 = v1.currently_viewing();
		n_play1.info();
		System.out.println("Viewer1 last version:");
		v1.show_list();

		System.out.println("-----------------------------");

		//Unregistering player1 from the dataset
		ds.remove_observer(p1);

		//Adding new videos to the dataset  
		ds.add(new Audio("newAudio1", "10", "mp3"));
		ds.add(new Audio("newAudio2", "10", "dolby atmos"));
		
		//Showing the lists after updates
		System.out.println("After player1 is unregistered ");
		p1.show_list();
		System.out.println("-----------------------------");
		System.out.println("Player2 is shown after uptade");
		p2.show_list();
		System.out.println("-----------------------------");
		System.out.println("Viewer2 is shown after uptade");
		v2.show_list();
	}
}