const User = require("./DataBase/User.js");

class authController {
    async registration(req,res){
        try{
const {username, password} = req.body;
let candidate = {username: ""};
            candidate = findone({username: username});
        }catch(e){
console.log(e);
            res.status(400).json('Ошибка при регистрации');
        }
    }
    async login(req,res){
        try{

        }catch(e){

        }
    }
    async getUsers(req,res){
        try{

        }catch(e){

        }
    }
}

module.exports = new authController(); //Экспортируем обьект данного класса