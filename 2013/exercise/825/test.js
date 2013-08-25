

var http =require("http");
var url = require("url");
function start(){
    console.log("call the start");
    function onRequest(request,response){
        console.log("call the onRequest function");
        response.writeHead(200,{"Content-type":"text/plain"});
        response.write("aa");
        response.end();
    }
    http.createServer(onRequest).listen(17880);
    console.log("Server has started.");
}
exports.start = start;
