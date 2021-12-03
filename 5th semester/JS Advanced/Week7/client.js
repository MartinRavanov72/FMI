const http = require('http');
const url = "http://localhost:8000";
var request = require('sync-request');

class Delivery{
    constructor() {
        return new Proxy(this, {
            get: async (obj, prop) => {
                return (new Promise((resolve, rej) => {
                    http.get([url, 'load', prop].join('/'), res =>
                        res.on('data', chunk =>
                            resolve(chunk.toString()))
                    );
                }));
                
            },
            set: (obj, prop, value) => {
                request('GET', [url, 'store', prop, value].join('/'));
            }
        })
    }
}

(async () => {
    const delivery = new Delivery();
    console.log(await delivery.testProp);
    delivery.p2 = 'asd';
    console.log(await delivery.p2);
    console.log(await delivery.testProp);
    delivery.testAgain = 'testvalue2';
    console.log(await delivery.testAgain);
})();
