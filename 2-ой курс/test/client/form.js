
	const form_handleR = async (event) => {  //Создаем ассинхронный callback, чтобы при событии 'submit' страница не перезагружалась
		event.preventDefault() // Если событие не обрабатывается явно, то оно не должно вести себя обычно
		const request = await fetch('/form', { // создаем fetch обьект, которыйы может отправлять сетевые запросы на сервер и подгружать инфу.
			// в него передаем URL формы
			method: 'POST', // Метод 'отправить'
			headers: { //Заголовки, чтобы сервер понимал тип обрабатываемой информации
				'Content-Type': 'application/json', //Информация контента json
				'Accept': 'application/json', //Принающая инфа. json
			},

			body: JSON.stringify(Object.fromEntries((new FormData(event.target)).entries()))
			// event.target - наша форма из обьекта fetch, c помощью конструктора new FormData мы считываем с нашей форма данные
			// т.е. происходит отправка формы. // преобразуем форму в обьект данных с помощью fromEntries и возвращаем массив
			// перечисляемых пар свойств c помощью entries. Преобразуем массив в json формат с помощью stringify
		});
		const response = await request.json(); // Ждем ответ от запроса
		if (!request.ok) {
			alert(response.errors); // если его нет, то ошибка
		} else {
			document.querySelector('form').insertAdjacentHTML(
				'afterend',
				`<h1 style="color: red">${response}</h1>`);
		}
	}

	const form_handleG = async (event) => {  //Создаем ассинхронный callback, чтобы при событии 'submit' страница не перезагружалась
		event.preventDefault() // Если событие не обрабатывается явно, то оно не должно вести себя обычно
		const request = await fetch('/form', { // создаем fetch обьект, которыйы может отправлять сетевые запросы на сервер и подгружать инфу.
			// в него передаем URL формы
			method: 'POST', // Метод 'отправить'
			headers: { //Заголовки, чтобы сервер понимал тип обрабатываемой информации
				'Content-Type': 'application/json', //Информация контента json
				'Accept': 'application/json', //Принающая инфа. json
			},

			body: JSON.stringify(Object.fromEntries((new FormData(event.target)).entries()))
			// event.target - наша форма из обьекта fetch, c помощью конструктора new FormData мы считываем с нашей форма данные
			// т.е. происходит отправка формы. // преобразуем форму в обьект данных с помощью fromEntries и возвращаем массив
			// перечисляемых пар свойств c помощью entries. Преобразуем массив в json формат с помощью stringify
		});
		const response = await request.json(); // Ждем ответ от запроса
		if (!request.ok) {
			alert(response.errors); // если его нет, то ошибка
		} else {
			document.querySelector('form').insertAdjacentHTML(
				'afterend',
				`<h1 style="color: green">${response}</h1>`);
		}
	}
	const form_handleY = async (event) => {  //Создаем ассинхронный callback, чтобы при событии 'submit' страница не перезагружалась
		event.preventDefault() // Если событие не обрабатывается явно, то оно не должно вести себя обычно
		const request = await fetch('/form', { // создаем fetch обьект, которыйы может отправлять сетевые запросы на сервер и подгружать инфу.
			// в него передаем URL формы
			method: 'POST', // Метод 'отправить'
			headers: { //Заголовки, чтобы сервер понимал тип обрабатываемой информации
				'Content-Type': 'application/json', //Информация контента json
				'Accept': 'application/json', //Принающая инфа. json
			},

			body: JSON.stringify(Object.fromEntries((new FormData(event.target)).entries()))
			// event.target - наша форма из обьекта fetch, c помощью конструктора new FormData мы считываем с нашей форма данные
			// т.е. происходит отправка формы. // преобразуем форму в обьект данных с помощью fromEntries и возвращаем массив
			// перечисляемых пар свойств c помощью entries. Преобразуем массив в json формат с помощью stringify
		});
		const response = await request.json(); // Ждем ответ от запроса
		if (!request.ok) {
			alert(response.errors); // если его нет, то ошибка
		} else {
			document.querySelector('form').insertAdjacentHTML(
				'afterend',
				`<h1 style="color: yellow">${response}</h1>`);
		}
	}

	document.getElementById('form1').addEventListener('submit', form_handleR); // В документе выбираем обьект "форма", добавляем слушателя событий, события
// 'submit' каллбек 'form_handle'
	document.getElementById('form2').addEventListener('submit', form_handleG); // В документе выбираем обьект "форма", добавляем слушателя событий, события
	// 'submit' каллбек 'form_handle'
	document.getElementById('form3').addEventListener('submit', form_handleY); // В документе выбираем обьект "форма", добавляем слушателя событий, события
	// 'submit' каллбек 'form_handle'