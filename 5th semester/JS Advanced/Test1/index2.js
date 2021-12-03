// Write a simple implementation of a EventEmitter class that when extended can be used to emit events and listen for certain events using the “emit" and “on” methods.
// For more information check the example bellow:


class EventEmitter {
    constructor() {
        this.info = {};
    }

    emit(str, content) {
        if (!this.info.hasOwnProperty(str)) {
            this.info[str] = [];
        }
        this.info[str].push(content);
    }

    on(str, cb) {
        let intervalId = setInterval(() => {
            if (this.info.hasOwnProperty(str)) {
                for (let content of this.info[str]) {
                    cb(content);
                }
                
                clearInterval(intervalId);
            }
        }, 100);
    }
}

const fs = require('fs');
class Reader extends EventEmitter {
    constructor(options) {
        super();
        this.options = options;
    }
    readFile(fileName) {
        fs.readFile(fileName, this.options, (err, content) => {
            if (err) {
                return this.emit('error', err);
            }

            this.emit('data', content);
        })
    }
}

const reader = new Reader({ encoding: 'utf8' });
reader.on('data', console.log);
reader.readFile('test.txt');
reader.readFile('test2.txt');