process.stdin.setEncoding("utf8");
process.stdin.resume();

var nrSongs = 0,
	nrSelect = 0,
	nrPlays = 0,
	input = [],
	data = [];

process.stdin.on("data", function(data) {

	// First chunk of input contains number of songs and number of songs to select
	if (nrSongs === 0) {
		var settings = data.split(' ');
		nrSongs = settings[0];
		nrSelect = settings[1];
	}

	// Push the rest of the data to an array and remove '\r\n'
	else {
		input.push(data.replace(/\r\n/g,'').split(' '));

		// Check to see if reached end of input
		if (input.length == nrSongs) {

			// Pause input and process data
			process.stdin.pause();
			process.nextTick(function() {
				processData();
			});
		}
	}
});

function processData() {
		// Grab number of plays for first track
	var i, nrPlays = int(input[0][0]);

	for (i = 0; i < input.length; i++) {
		var o = {};

		// Add song name and qi (qi = nrPlays / currentTrack)
		o.si = input[i][1];
		o.qi = int(input[i][0]) / (nrPlays / (i+1));

		// Push object to array...
		data.push(o);
	}

	// ... and sort array by qi
	var sorted = data.sort(function(a, b){
		return b.qi-a.qi;
	});

	// Write the track names
	for (i = 0; i < nrSelect; i++) {
		console.log(sorted[i].qi);
		console.log(sorted[i].si);
	}
}

function int(value) { return parseInt(value, 10); }