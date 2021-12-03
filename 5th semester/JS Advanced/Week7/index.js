const http = require('http');
const path = require('path');
const fs = require('fs');
const pagesDirectory = path.join(__dirname, 'pages');
const PORT = 8000;
const localJSONObject = {
    testProp: 'testPropValue'
};

const handleNotFound = (res) => {
    const notFoundFilePath = path.join(pagesDirectory, 'not-found.html');
    const readStream = fs.createReadStream(notFoundFilePath);
    readStream.on('ready', () => {
        res.writeHead(200, {
            'Content-Type': 'text/html'
        });
    });
    readStream.on('error', (err) => console.log(err));
    readStream.pipe(res);
};
const routes = {
    'notfound': handleNotFound
};
const server = http.createServer((req, res) => {
    const url = req.url;
    const urlLoadExpr = /load\/([0-9a-zA-Z-]*)/;
    const urlStoreExpr = /store\/([0-9a-zA-Z-]*)\/([0-9a-zA-Z-]*)/;
    if (urlLoadExpr.test(url)) {
        const propValue = url.match(urlLoadExpr);
        // console.log(propValue);
        if (propValue === null || localJSONObject[propValue[1]] === undefined) {
            // res.writeHead(301, {'Location': 'notfound'});
            handleNotFound(res);
            return;
        }
        const returnValue = localJSONObject[propValue[1]];
        res.write(returnValue);
        
    }
    if(urlStoreExpr.test(url)){
        const propValue = url.match(urlStoreExpr);
        localJSONObject[propValue[1]] = propValue[2];
    }


    res.end();

});
server.listen(PORT, () => {
    console.log(`Server is listening on ${PORT}...`)
});