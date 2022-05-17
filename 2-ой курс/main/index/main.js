import express from 'express'
import path from 'path'

const __dirname = path.resolve();
const PORT = 1007;
const app = express();

app.use(express.static(path.resolve(__dirname, 'static')));

app.get('/',(req, res) => {
    res.sendFile(path.resolve(__dirname, 'static','list_1.html'));

});



app.listen(PORT, () => {console.log("Сервер " + PORT + " запущен...")});
