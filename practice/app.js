var unirest = require("unirest");

var req = unirest("GET", "https://judge0.p.rapidapi.com/languages");

req.headers({
	"x-rapidapi-host": "judge0.p.rapidapi.com",
	"x-rapidapi-key": "2309734a5amsh86efe32ebb7e6b4p1528ccjsnba4f66b1ddef",
	"useQueryString": true
});


req.end(function (res) {
	if (res.error) throw new Error(res.error);

	console.log(res.body);
});