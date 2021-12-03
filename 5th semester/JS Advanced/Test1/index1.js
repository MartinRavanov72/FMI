// Write a simple implementation of a EventEmitter class that when extended can be used to emit events and listen for certain events using the “emit" and “on” methods.
// For more information check the example bellow:


class EventEmitter {
    constructor() {
        this.events = {};
        this.members = {};
        this.ons = {}
    }

    emit(key, content) {
        if (!this.events.hasOwnProperty(key)) {
            this.events[key] = [];
            this.members[key] = 0;
        }

        this.events[key].push(content);
        this.members[key]++;

        this.ons[key]()
    }

    on(key, cb) {
        

        this.ons[key] = cb;

        let intervalId = setInterval(() => {
            if (this.events.hasOwnProperty(key) && this.members[key] !== 0) {
                for (let content of this.events[key]) {
                    cb(content);
                    this.members[key]--;
                }
                
                if (this.members[key] === 0){
                    clearInterval(intervalId);
                } 
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