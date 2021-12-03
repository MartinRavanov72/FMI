class EventEmitter {
    constructor() {
        this.events = {};
        this.members = {};
    }

    emit(key, content) {
        if (!this.events.hasOwnProperty(key)) {
            this.events[key] = [];
            this.members[key] = 0;
        }

        this.events[key].push(content);
        this.members[key]++;
    }

    on(key, cb) {
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
