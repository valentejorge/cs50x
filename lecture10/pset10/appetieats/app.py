from flask import Flask
from appetieats.ext import sesssion

from appetieats.ext import database
from appetieats.routes.main import main_bp
from appetieats.ext import commands
from appetieats.ext import configuration
from appetieats.ext import error

app = Flask(__name__)

commands.init_app(app)
sesssion.init_app(app)
configuration.init_app(app)
database.init_app(app)
error.init_app(app)

app.register_blueprint(main_bp)