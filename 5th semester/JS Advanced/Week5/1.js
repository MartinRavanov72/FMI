
const stream = require('stream');
const fs = require('fs');

class RevisionStream extends stream.Transform {
    constructor(options) {
        super(options);
    }
    
    prevLastPiece = '';

    _transform(chunk, encoding, next) {
        chunk = this.prevLastPiece + chunk;
        const changedChunk = this._changeChunk(chunk);
        this.push(changedChunk);
        next();
    }

    _changeChunk(chunk) {
        const changedChunk = chunk.replace(/(Lorem|Ipsum)/g, '-----');
        this.prevLastPiece = changedChunk?.split(/\s+/).slice(-1)[0];
        return changedChunk.slice(0,changedChunk.length - this.prevLastPiece.length);
    }
}



const re = new RevisionStream();
fs.createReadStream('./test.txt', { highWaterMark: 10 })
.pipe(re)
.pipe(fs.createWriteStream('output.txt', {encoding: 'utf-8'}));




// const readStream = fs.createReadStream('./text.txt', { highWaterMark: 10 });
// const writeStream = fs.createWriteStream('./revision.txt');

// readStream.pipe(re).pipe(writeStream);