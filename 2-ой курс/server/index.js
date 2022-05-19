import express from 'express'
import path from 'path'
import User from "./DataBase/User.js";
const authRouter = require('authRouter.js');

const __dirname = path.resolve();
const PORT = 1007;
const app = express();

app.use(express.json);
app.use("/auth", authRouter);
app.use(express.static(path.resolve(__dirname,'server', 'static')));



    app.get('/', (req, res) => {
        res.sendFile(path.resolve(__dirname, 'server', 'static', 'index.html'));

    });


const start = () => {
    try {
    app.listen(PORT, () =>
        console.log("Сервер " + PORT + " запущен..."));
} catch (e) { console.log(e);}
}

start();